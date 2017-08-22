#include "custom_tree.h"
/* new typedef */
using bst=binary_search_tree;


/*
bst::iterator(std::unique_ptr<bst::node> curr = nullptr) : curr(curr) {
	this.curr = curr;
}
*/
/*
bool bst::iterator::operator != (const iterator &it) const {
	return it.curr != curr;
}

bst::node const& bst::iterator::operator * () const {
	return *curr->get();
}
*/
/*
   bst::node bst::iterator::operator -> () {
	return *curr.get();
}
*/
//pre
/*
bst::iterator &bst::iterator::operator ++ () {
	curr = &curr->get()->next;
	return *this;
}
//post
bst::iterator &bst::iterator::operator ++ (int) {
	curr = &curr->get()->next;
	return *this;
}


bst::iterator begin() {
	return iterator(bst::head);
}

bst::iterator end() {
	return iterator(nullptr);
}
*/

/* && means change of ownership */
void bst::node::set_left(std::unique_ptr<bst::node>&& newnext)
{
    left = std::move(newnext);
}

void bst::node::set_right(std::unique_ptr<bst::node>&& newnext)
{
    right = std::move(newnext);
}

int bst::size() const {
	return this_size;
}

bst::node * bst::node::get_left(void) const
{
    return left.get();
}

bst::node * bst::node::get_right(void) const
{
    return right.get();
}

bst::node * bst::node::get_parent(void) const
{
    return parent.get();
}

std::string bst::node::get_data(void) const
{
    return data;
}

std::unique_ptr<bst::node>& bst::node::get_left_ptr(void)
{
    return left;
}

std::unique_ptr<bst::node>& bst::node::get_right_ptr(void)
{
    return right;
}

std::unique_ptr<bst::node>& bst::node::get_parent_ptr(void)
{
    return parent;
}

bool bst::add(std::string data)
{
    node * current;
    node * prev = nullptr;
    std::unique_ptr<bst::node> newnode = std::make_unique<bst::node>(data);
    if(head == nullptr)
    {
        head = std::move(newnode);
        ++this_size;
        return true;
    }
    current = head.get();//get the pointer held by the unique_ptr
    while(current != nullptr)
    {

		if(current->data <= data) {
			if(current->left != nullptr) {
				//go left
				prev = current;
				current = current->get_left();
			} else {
				//insert left
				prev->set_left(std::move(newnode));
				break;
			}
		} else {
			if(current->right != nullptr) {
				//go right
				prev = current;
				current = current->get_right();
			} else {
				//insert right
				prev->set_right(std::move(newnode));
				break;
			}
		}


        //prev = current;
        //current = current->get_next();
    }/*
    if(!prev)
    {
        newnode->set_next(std::move(head));
        head = std::move(newnode);
    }
    else if(!current)
    {
        prev->set_next(std::move(newnode));
    }
    else
    {
        newnode->set_next(std::move(prev->get_next_ptr()));
        prev->set_next(std::move(newnode));
    }*/
    ++this_size;
    return true;
}


bool bst::search(std::string needle)
{
	node *current;
	if(head == nullptr) {
		return false;
	}
	current = head.get();

	while(current != nullptr && current->get_data() != needle) {
		if(current->get_data() < needle) {
			current = current->get_left();
		} else {
			current = current->get_right();
		}
	}
    return current != nullptr;
}
