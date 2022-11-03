from collections import deque

graph = {}

graph["you"] = ["alice","bob","claire"]
graph["bob"] = ["anuj","peggy"]
graph["alice"] = ["peggy"]
graph["claire"] = ["tom","jonny"]
graph["anuj"] = []
graph["peggy"] = []
graph["tom"] = []
graph["jonny"] = []

print(graph)
search_queue = deque()
search_queue += graph["you"]
searched = []
found = []
print(search_queue)

def person_is_seller(name):
    return name[-1] == 'm'

while search_queue:
    person = search_queue.popleft()
    if not person in searched:
        if person_is_seller(person):
            found.append(person)
        else:
            search_queue += graph[person]
            print(search_queue)
            searched.append(person)

if found:
    print(found[0].title() + " is mango seller!")
else:
    print("There is no path!")
