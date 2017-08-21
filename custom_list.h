#include <memory>
class linked_list
{

    /* linked_list::node */
    class node
    {
        std::string data;
        std::unique_ptr<node> next;

        public:
        node(std::string newdata) : data(newdata), next(nullptr) {}

        void set_next(std::unique_ptr<node>&& newnext);
        node * get_next(void) const;
        std::string get_data(void) const;
        std::unique_ptr<node>& get_next_ptr(void) const;
        friend class linked_list;
    };

	//friend struct iterator;

    int this_size;
    std::unique_ptr<node> head;
    public:
    linked_list(void) : head(nullptr), this_size(0) {}
    bool add(std::string);
    bool search(std::string);
	int size() const;
/*
	struct iterator {
		std::unique_ptr<node> *curr;

		iterator(std::unique_ptr<node> other) : curr(&other) {
			//curr = &other;
		}

		bool operator != (const iterator &it) const;
		node const& operator * () const;
		//node operator -> () const;
		iterator &operator ++ ();
		iterator &operator ++ (int);

	};
	iterator begin() const;
	iterator end() const;*/
};
