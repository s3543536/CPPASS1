#include <memory>
class binary_search_tree
{

    /* linked_list::node */
    class node
    {
        std::string data;
        std::unique_ptr<node> parent;
        std::unique_ptr<node> left;
        std::unique_ptr<node> right;

        public:
        node(std::string newdata) : data(newdata), parent(nullptr), left(nullptr), right(nullptr) {}

        void set_left(std::unique_ptr<node>&& newnext);
        void set_right(std::unique_ptr<node>&& newnext);
        node * get_left(void) const;
        node * get_right(void) const;
        node * get_parent(void) const;
        std::string get_data(void) const;
        std::unique_ptr<node>& get_left_ptr(void);
        std::unique_ptr<node>& get_right_ptr(void);
        std::unique_ptr<node>& get_parent_ptr(void);
        friend class binary_search_tree;
    };

	//friend struct iterator;

	public:
    std::unique_ptr<node> head;
    int this_size;
    public:
    binary_search_tree(void) : head(nullptr), this_size(0) {}
    bool add(std::string);
    bool search(std::string);
	int size() const;

	struct iterator {
		//binary_search_tree * const parent;
		const std::unique_ptr<node> *curr;
		const std::unique_ptr<node> *prev;

		iterator(const std::unique_ptr<node> *other) : curr(other), prev(nullptr) {}
		/*iterator(binary_search_tree const& parent) : parent(&parent), curr(&(parent.head)), prev(nullptr) {}
		iterator(binary_search_tree const& parent, std::unique_ptr<node> *other) : parent(&parent), curr(other), prev(nullptr) {}
*/

		bool operator != (const iterator &it) const;
		node * operator * () const;
		//node operator -> () const;
		iterator &operator ++ ();
		iterator &operator ++ (int);

	};
	iterator begin() const;
	iterator end() const;
};
