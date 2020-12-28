/*******平衡二叉树（AVL）***********/
#include <iostream>
using namespace std;

///平衡二叉树结点结构
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class AVLTree {
public:
  AVLTree() { root = NULL; }
  ~AVLTree() { destroy(root); }

  ///从命令行接受数据创建AVL树。使用其他方式创建原理一致
  void Create() {
    cout << "input numbers to create AVL: " << endl;
    int temp;
    while (cin >> temp) {
      root = Insert(root, temp);
    }
    cout << "AVL创建完成！" << endl;
    Print();
  }

  ///返回某结点为根节点的子树高度
  int Height(TreeNode *p) {
    if (p == NULL)
      return 0;
    int i = Height(p->left);
    int j = Height(p->right);
    return i > j ? i + 1 : j + 1;
  }

  ///输出该排序树
  void Print() {
    cout << "中序遍历为： ";
    MidOrder(root);
    cout << endl;
    cout << "先序遍历为： ";
    PreOrder(root);
    cout << endl;
  }

  ///先序遍历输出
  void PreOrder(TreeNode *p) {
    if (p != NULL) {
      cout << p->val << " ";
      PreOrder(p->left);
      PreOrder(p->right);
    }
  }
  ///中序遍历输出
  void MidOrder(TreeNode *p) {
    if (p != NULL) {
      MidOrder(p->left);
      cout << p->val << " ";
      MidOrder(p->right);
    }
  }

  ///简化版插入函数
  void Insert(const int x) { root = Insert(root, x); }

  ///简化版删除函数
  void Remove(int x) { root = Remove(root, x); }

  ///返回值为x的结点指针
  TreeNode *Search(int x) {
    TreeNode *p = root;
    while (p) {
      if (p->val == x)
        break;
      else if (p->val < x)
        p = p->right;
      else
        p = p->left;
    }
    return p;
  }

  ///返回子树最大值结点的指针
  TreeNode *TreeMax(TreeNode *subTree) {
    if (!subTree)
      return NULL;
    while (subTree->right) {
      subTree = subTree->right;
    }
    return subTree;
  }

  ///返回子树最小值结点的指针
  TreeNode *TreeMin(TreeNode *subTree) {
    if (!subTree)
      return NULL;
    while (subTree->left) {
      subTree = subTree->left;
    }
    return subTree;
  }

private:
  ///根节点
  TreeNode *root;

  ///插入（视为在某结点为根节点的子树上进行插入）
  //对子树上进行插入操作后都需要平衡操作，可能会改变该子树的根节点，
  //因此设置返回值记录完成操作后子树的根结点指针)
  TreeNode *Insert(TreeNode *subRoot, const int k) {
    if (subRoot == NULL) {
      subRoot = new TreeNode(k);
    } else if (k > subRoot->val) //需要在右子树上插入新的结点
    {
      subRoot->right = Insert(subRoot->right, k);
      //在右子树上插入结点后可能导致不平衡，故需要对右子树进行平衡操作
      //而平衡操作可能会导致子树根结点产生变化，故需更新当前的子树根节点
      subRoot = Balancee(subRoot);
    } else if (k < subRoot->val) { //需要在左子树上插入新的结点
      subRoot->left = Insert(subRoot->left, k);
      //和上面同理
      subRoot = Balancee(subRoot);
    }
    //将新的子树根结点指针返回供原父节点更新孩子指针
    return subRoot;
  }

  ///删除结点（视为在该结点为根节点的树上进行删除操作）
  TreeNode *Remove(TreeNode *subRoot, int x) {
    if (!Search(x)) { //不存在x的结点则直接返回
      cout << "不存在值为" << x << "的结点！" << endl;
      return root;
    }

    if (!root) // root为空指针都直接返回NULL
      return root;

    if (subRoot->val == x) //情况1：要删除的就是该树的根节点
    {
      if (subRoot->left && subRoot->right) //情况1.1：该树的左右子树都存在
      {
        if (BalanceFactor(subRoot) > 0) {
          //左子树高于右子树，则根节点的值替换为其直接前驱的值，然后转化为删除
          //其直接前驱(其位于左子树上，也就意味着去降低左子树高度)
          TreeNode *tmp = TreeMax(subRoot->left); //直接前驱就是左子树的最大值
          subRoot->val = tmp->val;
          //递归调用Remove()删除subRoot的左子树上的前驱结点后，Remove()返回可能为
          //新的subRoot的左子树根节点供subRoot更新左孩子结点((Remove()会调用Balance()函数平衡其操作的树))。
          subRoot->left = Remove(subRoot->left, tmp->val);
        } else {
          //右子树高于左子树，则根节点的值替换为其直接后继的值，
          //然后转化为删除其直接后继(其位于右子树上，也就意味着去降低右子树高度)
          TreeNode *tmp = TreeMin(subRoot->right);
          subRoot->val = tmp->val;
          subRoot->right = Remove(subRoot->right, tmp->val);
        }
      } else //情况1.2：只存在一颗子树或者都不存在
      {
        //直接将根节点更新为其孩子结点(都不存在则为NULL)
        TreeNode *tmp = subRoot;
        subRoot = (subRoot->left) ? (subRoot->left) : (subRoot->right);
        delete tmp;
        tmp = NULL;
      }
    } else if (x < subRoot->val) { //情况2：要删除的节点位于左子树上
      //递归调用,在subRoot的左子树上进行删除操作，并返回新的左子树根节点供subRoot更新左孩子指针
      subRoot->left = Remove(subRoot->left, x);
      //在subRoot的左子树上完成删除操作后,可能导致该树不平衡,故需要进行平衡操作并更新当前根节点
      if (BalanceFactor(subRoot) < -1)
        subRoot = Balancee(root);
    } else { //情况3：要删除的节点位于右子树上
      //递归调用,在subRoot的右子树上进行删除操作，并返回新的右子树根节点供subRoot更新右孩子指针
      subRoot->right = Remove(subRoot->right, x);
      //在subRoot的右子树上完成删除操作后,可能导致该树不平衡,故需要进行平衡操作并更新当前根节点
      if (BalanceFactor(subRoot) > 1)
        subRoot = Balancee(subRoot);
    }
    //返回该树当前根节点供其父节点更新孩子节点
    return subRoot;
  }

  ///返回某个节点的平衡因子
  int BalanceFactor(TreeNode *p) { return Height(p->left) - Height(p->right); }

  ///对某个结点进行平衡操作（根据平衡因子调用四种不同的旋转操作）
  TreeNode *Balancee(TreeNode *subRoot) {
    int bf = BalanceFactor(subRoot);
    if (bf > 1) //左子树更高
    {
      if (BalanceFactor(subRoot->left) > 0)
        //左孩子结点平衡因子>0说明新节点多在了左子树上，因此调用LL_Rotation
        subRoot = LL_Rotation(subRoot);
      else
        //左孩子结点平衡因子<0说明新节点多在了右子树上，因此调用LR_Rotation
        subRoot = LR_Rotation(subRoot);
    } else if (bf < -1) //右子树更高
    {
      if (BalanceFactor(subRoot->right) > 0)
        //右孩子结点平衡因子>0说明新节点多在了左子树上，因此调用RL_Rotation
        subRoot = RL_Rotation(subRoot);
      else
        //右孩子结点平衡因子<0说明新节点多在了右子树上上，因此调用RR_Rotation
        subRoot = RR_Rotation(subRoot);
    }
    //对分支结点进行平衡操作后可能会更新该分支节点，故将新的分支结点返回供原父结点更新孩子指针
    return subRoot;
  }

  /*****************************
            四种旋转操作
  ******************************/
  /// LL平衡旋转(右单旋转)
  //在左孩子(L)的左子树(L)上插入导致不平衡，需要向右旋转一次实现平衡
  TreeNode *LL_Rotation(TreeNode *subRoot) {
    TreeNode *temp = subRoot->left;
    subRoot->left = temp->right;
    temp->right = subRoot;
    //完成旋转操作之后，该处分支结点(原为subRoot)发生了变化，
    //因此要返回新的分支节点指针供其父节点更新孩子指针
    return temp;
  }

  /// RR平衡旋转(左单旋转)
  //在右孩子(R)的右子树(R)上插入导致不平衡，需要向左旋转一次实现平衡
  TreeNode *RR_Rotation(TreeNode *subRoot) {
    TreeNode *temp = subRoot->right;
    subRoot->right = temp->left;
    temp->left = subRoot;
    //完成旋转操作之后，该处分支结点(原为subRoot)发生了变化，
    //因此要返回新的分支节点指针供其父节点更新孩子指针
    return temp;
  }

  /***********下面两种情况可看作是对根节点和子节点进行上两种旋转操作的组合*****************/
  /// RL平衡旋转(先右后左双旋转)
  //在右孩子(R)的左子树(L)上插入导致不平衡，需要先对分支结点的右孩子进行一次右旋(LL_Rotation),
  //再对分支结点进行一次左旋(RR_Rotation)
  TreeNode *RL_Rotation(TreeNode *subRoot) {
    //对subRoot右孩子结点LL旋转后，更新subRoot右结点指针
    subRoot->right = LL_Rotation(subRoot->right);
    return RR_Rotation(
        subRoot); //返回新的分支结点供原分支节点的父节点更新孩子指针
  }

  /// LR平衡旋转(先左后右双旋转)
  //在左孩子(L)的右子树(R)上插入导致不平衡,需要先对分支结点的左孩子进行一次左旋(RR_Rotation),
  //再对分支结点进行一次右旋(LL_Rotation)
  TreeNode *LR_Rotation(TreeNode *subRoot) {
    //对subRoot左结点RR旋转后，更新subRoot左结点指针
    subRoot->left = RR_Rotation(subRoot->left);
    return LL_Rotation(
        subRoot); //返回新的分支结点供原分支节点的父节点更新孩子指针
  }

  ///销毁该树
  void destroy(TreeNode *p) {
    if (p) {
      destroy(p->left);
      destroy(p->right);
      delete p;
    }
  }
};

int main() {
  /// 8.平衡二叉树
  AVLTree avl;
  avl.Create();
  int iterTimes = 9;
  cout << "删除测试：" << endl;
  for (int i = 1; i < iterTimes; i++) {
    avl.Remove(i);
    cout << "删除 " << i << " 后: " << endl;
    avl.Print();
  }
  cout << endl;
}
