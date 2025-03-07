#pragma once


namespace stk {
    template<class T, class FRIEND>
    class ListNode
    {
    private:
        T value;
        ListNode *next;

    public:
        ListNode(void) {
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

        friend FRIEND;
    };

    template<class T>
    class Stack {
        typedef class ListNode<T, Stack<T>> Node;
        Node *top;
    public:
        Stack(void) {
            top = nullptr;
        }
        ~Stack(void) {
            while (top != nullptr) {
                Pop();
            }
        }
        bool IsEmpty(void) {
            if (top == nullptr)
                return true;
            return false;
        }
        void Push(T n) {
            Node *newNode = new Node(n, top);
            top = newNode;
        }
        T Pop(void) {
            if (top == nullptr)
                throw std::out_of_range("Stack is empty");
            Node* old_top = top;
            T value = old_top->value;
            top = top->next;
            delete old_top;
            return value;
        }
        T TopValue(void) {
            if (top == nullptr)
                throw std::out_of_range("Stack is empty");
            return top->value;
        }
    };
}
