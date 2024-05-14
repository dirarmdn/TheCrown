// Fungsi untuk mencari node dengan nama tertentu
address search_node(address root, char name) {
    if (root == NULL)
        return NULL;
    
    if (root->nama == name)
        return root;
    
    address result = search_node(root->fs, name); // Search in first son
    if (result == NULL)
        result = search_node(root->nb, name);     // Search in next brother
    
    return result;
}
