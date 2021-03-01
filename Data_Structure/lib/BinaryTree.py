class BinNode:
    def __init__(self,data):
        self.data=data
        self.left=None
        self.right=None

class BinTree:
    def __init__(self,data):
        self.root=BinNode(data)

    def preprint(self,r):
        if r is None:
            return
        print(r.data,end=' ')
        self.preprint(r.left)
        self.preprint(r.right)

    