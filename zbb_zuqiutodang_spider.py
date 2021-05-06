import requests
from bs4 import BeautifulSoup
import re



'''
def __analysis(self, htmls):
        

        anchors = []
        for html in root_html:
            name = re.findall(Spider.name_pattern, html)
            number = re.findall(Spider.number_pattern, html)
            anchor = {'name':name, 'number':number}
            anchors.append(anchor)
'''


if __name__ == '__main__':
    target = 'https://news.zhibo8.cc'
    req = requests.get(url=target)
    req.encoding = 'utf-8'
    
    html = req.text

    content = str(BeautifulSoup(html,'lxml'))

    root_pattern = '<a href="//news.zhibo8.cc/zuqiu/2021-05-06/([\s\S]*?).htm" target="_blank">([\s\S]*?)</a>'

    print(type(content))
    print(type(root_pattern))
    #print(content)


    root_html = re.findall(root_pattern, content)

    #url = content.find_all('a')

    #content1 = BeautifulSoup(str(url),)'html5lib')

    #print(content.url)
    #print(content.title.text)

    


    #content1 = content.find('div',id = 'body')

    #这里比较find和find_all的区别
    #content2 = content1.find_all('div',{"class":"content"},{"style":"height"})
    #print(content2)
    #content2.list(text)

    '''
    for link in content2.find_all('a'):
        print(link.a.string)
    '''

    for i in root_html:
        print(i[1])
    

    


    

