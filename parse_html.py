from reprlib import recursive_repr
from bs4 import (
    BeautifulSoup,
    element
)

def dump(content):
    print("##########")
    print(content)
    print("##########")


class paser():
    def __init__(self, html_path):
        self._html_path = html_path
        self._soup = None
        pass

    def init_html(self):
        with open(self._html_path, "r") as fp:
            html_str = fp.read()
        self._soup = BeautifulSoup(html_str, "html.parser")

    def get_total_number(self):
        body = self._soup.body
        table = body.find(id="result_table")
        total_row = body.find(id="total_row")
        tds = total_row.find_all(name="td")

        total_count = int(tds[1].string)
        total_pass = int(tds[2].string)
        total_fail = int(tds[3].string)
        return total_count, total_pass, total_fail

    def get_case_list(self):
        pass_list = list()
        fail_list = list()

        body=self._soup.body
        table= body.find(id="result_table")
        header_row = table.find(id="header_row")
        for sibling in header_row.find_next_siblings(name="tr"):
            if sibling.get("class", None) is None:
                continue
            if sibling.get("class")[0] in ["passClass", "failClass"]:
                suit_name = sibling.td.string
            # 获取失败用例的详细
            elif sibling.get("class")[0] == "none":
                test_case_name = self.get_case_name(suit_name, sibling)
                start_time, end_time =self.get_start_end_time(sibling)
                fail_list.append(test_case_name)
            # 获取成功用例的详细
            elif sibling.get("class")[0] == "hiddenRow":
                test_case_name = self.get_case_name(suit_name, sibling)
                start_time, end_time =self.get_start_end_time(sibling)
            pass_list.extend(fail_list)
        return pass_list

    def get_case_name(self, suit_name, tag):
        return ".".join((suit_name,tag.td.string))

    def get_start_end_time(self, tag):
        divs = tag.find_all(name="div")
        for div in divs:
            if div.get("id") is None:
                continue
            pre = div.find(name="pre")
            detail_string = pre.string
            lines = detail_string.splitlines()
            for line in lines:
                if line.startswith("[start time]="):
                    start_time = line.partition("[start time]=")[-1]
                if line.startswith("[end time]="):
                    end_time = line.partition("[end time]=")[-1]
            return start_time, end_time

if __name__ == "__main__":

    report = paser(r"./reports/html_report.html")
    report.init_html()
    total = report.get_total_number()
    report.get_case_list()
