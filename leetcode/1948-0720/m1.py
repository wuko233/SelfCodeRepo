from collections import defaultdict
from typing import List


class Tree:

    def __init__(self, name):
        self.name = name
        self.children = {}
        self.onlycode = ""
    
    def summonOnlycode(self, code_map):

        # End of tree
        if not self.children:
            self.onlycode = "#"
            return self.onlycode

        children_codes = []
        for name, children in sorted(self.children.items()):
            child_code = children.summonOnlycode(code_map)
            children_codes.append(f"{name}:{child_code}")
        self.onlycode = f"{self.name}:{''.join(children_codes)}"
        code_map[self.onlycode].append(self)
        return self.onlycode



class Solution:
    def deleteDuplicateFolder(self, paths: List[List[str]]) -> List[List[str]]:
        
        paths.sort()

        # Summon tree struction
        home = Tree("")
        for path in paths:
            cur = home
            for dir in path:
                if dir not in cur.children:
                    cur.children[dir] = Tree(dir)
                cur = cur.children[dir]
        

        code_map = defaultdict(list)
        home.summonOnlycode(code_map)

        deleted = set()

        def marked_deleted(tree):
            deleted.add(tree)
            for child in tree.children.values():
                marked_deleted(child)
        
        for dirs in code_map.values():
            if len(dirs) > 1: # multiple dirs which hava same onlycode
                for dir in dirs:
                    marked_deleted(dir)

        result = []

        def dfs_collect(tree, cur_path):
            if tree in deleted:
                return
            new_path = cur_path + [tree.name]
            if tree != home:
                result.append(new_path)
            for child in tree.children.values():
                dfs_collect(child, new_path)

        dfs_collect(home, [""])
        return result
        

