class TreeNode:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

def bfs_binary_tree(root):
    if not root:
        return

    visited = set()
    queue = [root]

    while queue:
        current = queue.pop(0)

        if current not in visited:
            print(current.value, end=" ")
            visited.add(current)

            if current.left:
                queue.append(current.left)
            if current.right:
                queue.append(current.right)

# Example binary tree
#        1
#       / \
#      2   3
#     / \
#    4   5

root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
root.left.left = TreeNode(4)
root.left.right = TreeNode(5)

print("BFS on Binary Tree:")
bfs_binary_tree(root)
