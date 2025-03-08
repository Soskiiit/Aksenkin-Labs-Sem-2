#pragma once


namespace stk {
    template<class T, class FRIEND>
    class ListNode
    {
    private:
        T value;
        ListNode *next;

    public:
        ListNode() {
            next = nullptr;
        }

        ListNode(T value) {
            this->value = value;
            next = nullptr;
        }

        ListNode(T value, ListNode *next) {
            this->value = value;
            this->next = next;
        }

        ListNode(const ListNode &other) {
            this->value = other.value;
            this->next = other.next;
        }

        ListNode &operator=(const ListNode &other) {
            this->value = other.value;
            this->next = other.next;
            return *this;
        }

        friend FRIEND;
    };

    template<class T>
    class Stack {
        typedef class ListNode<T, Stack<T>> Node;
        Node* top;
    public:
        Stack() {
            top = nullptr;
        }

        Stack(Stack<T> &other) {
            top = nullptr;
            if (other.top == nullptr) return;
            top = new Node(*other.top);

            Node* this_ptr = top;
            Node* other_ptr = other.top;
            while (other_ptr != nullptr) {
                if (other_ptr->next == nullptr) {
                    this_ptr->next = nullptr;
                } else {
                    this_ptr->next = new Node(*other_ptr->next);
                }
                this_ptr = this_ptr->next;
                other_ptr = other_ptr->next;
            }
        }

        Stack operator= (Stack<T> &other) {
            while (top != nullptr)
                Pop();

            top = nullptr;
            if (other.top == nullptr) return *this;
            top = new Node(*other.top);

            Node* this_ptr = top;
            Node* other_ptr = other.top;
            while (other_ptr != nullptr) {
                if (other_ptr->next == nullptr) {
                    this_ptr->next = nullptr;
                } else {
                    this_ptr->next = new Node(*other_ptr->next);
                }
                this_ptr = this_ptr->next;
                other_ptr = other_ptr->next;
            }
            return *this;
        }

        ~Stack() {
            while (top != nullptr)
                Pop();
        }

        bool IsEmpty() {
            if (top == nullptr)
                return true;
            return false;
        }

        void Push(T n) {
            Node *newNode = new Node(n, top);
            top = newNode;
        }

        T Pop() {
            if (top == nullptr)
                throw std::out_of_range("Stack is empty");
            Node* old_top = top;
            T value = old_top->value;
            top = top->next;
            delete old_top;
            return value;
        }

        T TopValue() {
            if (top == nullptr)
                throw std::out_of_range("Stack is empty");
            return top->value;
        }
    };
}
