# encoding: utf-8
import requests
import os
from bs4 import BeautifulSoup

def getHTMLText(url):
	try:
		r = requests.get(url, timeout=30)
		r.raise_for_status()	#如果状态不是200，抛出HTTPError异常
		r.encoding = r.apparent_encoding
		return r.text
	except:
		print "产生异常"

def getPic(url):
	try:
		path = 'E://HokCode//trunk//pythonText//pic/'
		r = requests.get(url)
		r.raise_for_status()
		with open(path, 'wb') as f:
			f.write(r.content)
			F.close()
	except:
		print "产生异常"

if __name__ == "__main__":
	url = "https://python123.io/ws/demo.html"
	r = requests.get(url)
	demo = r.text
	soup = BeautifulSoup(demo, "html.parser")
	print(soup.prettify())


	# http://images.zon100.com/img/10000964/1000119726/1000141811_1000.jpg
	
'''
与requests库的7种核心方法：

request
requests库原始方法，以下方法都是用它封装
	r =requests.request(method, url, **kwargs)
		methoc:对应以下6种方法
		**kwargs:
			params：增加到url中的参数，服务器根据参数筛选资源返回
			data:	主要用于post，data内容作为资源提交
			json:	JSON格式数据
			header:	设置访问url的头信息.如：设置'user-agent'
			cookies:
			auth:	支持HTTP认证功能
			files:	传送文件
			timeout:设置超时时间
			proxies:设置代理服务器，防止爬虫逆追中
			allow_redirects:True/False，默认为True。重定向看管
			stream:	True/False，默认为True。获取内容立即下载开关。
head
用很少网络流量获取URL概要信息
	r = requests.head(URL)
	r.headers	

post/patch
向URL提交资源。提交字典，会整理在form表单下；提交字符串，会整理在data下
	payload = {"key1": "value1", "key2": "value2"}
	r = requests.post(URL, data = payload)
	print r.text
		"from":{
			"key1": "value1", 
			"key2": "value2"}
		}

'''

'''
BeautifulSoup
解析HTML/XML文件的功能库

5种基本元素：
	Tag
		标签，最基本的信息组织单元
	Name
		标签的名字。如：<p>...</p>的名字是'p'，格式：<tag>.name
	Attributes
		标签的属性，返回字典类型。<tag>.attrs
	NavigableString
		标签内非属性字符串，格式：<tag>.string
	Comment
		标签内字符串的注释部分

'''

BeautifulSoup标签树遍历:

下行遍历（遍历子节点标签）：
	.content
		将<tag>所有儿子节点存入列表
	.children
		子节点迭代类型，与.contents类似，用于循环遍历儿子节点
	.descendants
		子孙节点的迭代类型，包含所有子孙节点，用于循环遍历

上行遍历（遍历父节点标签）：
	.parent
		返回节点父亲标签
	.parents
		返回先辈标签的迭代类型，用于循环遍历先辈标签
 	
 	最高级标签的父亲是自己

平行遍历（返回同一父节点下，同一层级标签）：
	.next_sibling
		返回下一个平行节点标签
	.next_siblings
		返回后续平行节点标签的迭代类型

	.previous_sibling
		返回上一个平行节点标签
	.previous_siblings
		返回前续平行节点标签的迭代类型