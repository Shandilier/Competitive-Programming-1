void calc(Node *root,Node **head)
{
    if(!root)
        return;
    calc(root->right,head);
    if(head)
    {
        (*head)->prev = root;
    }
    root->next = *head;
    *head = root;
    calc(root->left,head);
}

Node *BstToDll(Node *root)
{
    if(!root)
        return;
    Node *head = NULL;
    calc(root,&head);
}