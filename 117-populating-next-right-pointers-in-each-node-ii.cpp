//http://www.cnblogs.com/yuzhangcmu/p/4041345.html

/*
    Solution 3: iterator with O(1) space.
*/
    public void connect(TreeLinkNode root) {
      if (root == null) {
        return;
      }

      connIterator(root);
    }

/*
    This is a iterator version. 
*/
    public void connIterator(TreeLinkNode root) {
      TreeLinkNode leftEnd = root;
      while (leftEnd != null) {
        TreeLinkNode p = leftEnd;

        // Connect all the nodes in the next level together.
        while (p != null) {

          // find the
          TreeLinkNode next = findLeftEnd(p.next);

          if (p.right != null) {
            p.right.next = next;
            next = p.right;
          }

          if (p.left != null) {
            p.left.next = next;
          }

          // continue to deal with the next point.
          p = p.next;
        }

        // Find the left end of the NEXT LEVEL.
        leftEnd = findLeftEnd(leftEnd);  //update leftEnd
      }

    }

// Find out the left end of the next level of Root TreeNode.
    public TreeLinkNode findLeftEnd(TreeLinkNode root) {
      while (root != null) {
        if (root.left != null) {
          return root.left;
        }

        if (root.right != null) {
          return root.right;
        }

        root = root.next;
      }

      return null;
    }
