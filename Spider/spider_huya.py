'''
  This is a module
'''
import re
import ssl


from urllib import request
# 断点调试
# BeautifulSoup , Scrapy
# 爬虫、反爬虫、反反爬虫
# ip 封
# 代理ip库
ssl._create_default_https_context = ssl._create_unverified_context

class Spider():
    '''
     This is a class
    '''
    # url = 'https://www.panda.tv/cate/kingglory'
    url = 'https://www.huya.com/g/lol'
    list_pattern = '<li class="game-live-item" gid="1" data-lp="[\d]*">([\s\S]*?)</li>'
    name_pattern = '<i class="nick" title="([\s\S]*?)">[\s\S]*?</i>'
    number_pattern = '<i class="js-num">([\s\S]*?)</i>'

    def __fetch_content(self):
        r = request.urlopen(Spider.url) # This is a HTTP request 

        # This is ....
        htmls = r.read() 
        htmls = str(htmls, encoding='utf-8')
        return htmls

    def __analysis(self, htmls):
        list_html = re.findall(Spider.list_pattern, htmls)

        anchors = []
        for html in list_html:
            name = re.findall(Spider.name_pattern, html)
            number = re.findall(Spider.number_pattern, html)
            anchor = {'name':name, 'number':number}
            anchors.append(anchor)

        return anchors
    
    def __refine(self, anchors):
        l =  lambda anchor: {
            'name':anchor['name'][0].strip(),
            'number':anchor['number'][0]
            }
        return map(l, anchors)

    def __sort(self, anchors):
        #filter
        anchors = sorted(anchors, key=self.__sort_seed,reverse=True)
        return anchors

    def __sort_seed(self, anchor):
        # \d*
        # 118.7万
        r = re.findall('[1-9]\d*\.?\d*', anchor['number'])
        number = float(r[0])
        print(number)
        if '万' in anchor['number']:
            number *= 10000
        return number

    def __show(self, anchors):
        for rank in range(0, len(anchors)):
            print('rank ' + str(rank + 1)
            + '  : '+ anchors[rank]['name']
            + '   ' + anchors[rank]['number'])

    def go(self):
        htmls = self.__fetch_content()
        anchors = self.__analysis(htmls)
        anchors = list(self.__refine(anchors))
        anchors = self.__sort(anchors)
        self.__show(anchors)

spider = Spider()
spider.go()
