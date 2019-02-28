import requests
from bs4 import BeautifulSoup as bs

result = requests.get('https://cpbook.net/methodstosolve')
soup = bs(result.text, 'html.parser')

data = []
rows = soup.find('table').find('tbody').find_all('tr')
for row in rows:
    cols = row.find_all('td')
    cols = [ele.text.strip() for ele in cols]
    data.append([cols[0], cols[1], cols[2]])
    print (cols[0])
    print (cols[2])

