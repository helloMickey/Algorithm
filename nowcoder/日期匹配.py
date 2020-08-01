import re
if __name__ == "__main__":
    # "DD-MM-YYYY"
    s = "01-08-202020-09-2020"
    p = '\d{2}-\d{2}-\d{4}'
    print(re.findall(p,s))