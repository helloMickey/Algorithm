"""
正则表达式
python 中的 re 模块
findall：在字符串中找到正则表达式所匹配的所有子串，并返回一个列表，
如果没有找到匹配的，则返回空列表。
"""
import re

if __name__ == "__main__":
    p = '^\s*-{0,1}\d+'
    s = "  dd -132 wiith"
    a  = re.search(p, s)
    print(s[a.span()[0] : a.span()[1]])
    
    pass