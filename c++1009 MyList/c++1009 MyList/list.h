#pragma once

namespace G{
	template<class T>
	class ListNode{
	public:
		T m_val;
		ListNode* m_prev;
		ListNode* m_next;

		ListNode(const T& val = T()) :
			m_prev(nullptr),
			m_next(nullptr),
			m_val(val){}
	};

	template<class T>
	class list{
		ListNode<T>* m_head;

		void createHead(){
			m_head = new ListNode<T>;
			m_head->m_next = m_head->m_prev = m_head;
		}

	public:
		class iterator{
		public:
			ListNode<T>* m_pos;

			iterator(ListNode<T> * val = nullptr) :
				m_pos(val){}

			T & operator *(){
				return m_pos->m_val;
			}

			T & operator ->(){
				return &m_pos->m_val;
			}

			iterator & operator++(){
				m_pos = m_pos->m_next;
				return *this;
			}

			iterator operator++(int){
				iterator tmp = *this;
				m_pos = m_pos->m_next;
				return tmp;
			}

			iterator & operator--(){
				m_pos = m_pos->m_prev;
				return *this;
			}

			iterator operator--(int){
				iterator tmp = *this;
				m_pos = m_pos->m_prev;
				return tmp;
			}

			bool operator==(const iterator & ci)const{
				return m_pos == ci.m_pos;
			}

			bool operator!=(const iterator & ci)const{
				return m_pos != ci.m_pos;
			}
		};

		list(){
			createHead();
		}

		list(int n, const T& val = T()){
			createHead();

			int i;
			for (i = 0; i < n; ++i){
				push_back(val);
			}
		}

		~list(){
			erase(begin(), end());
			delete m_head;
		}

		void push_back(const T& val){
			insert(end(), val);
		}

		iterator insert(iterator pos, const T & val){
			ListNode<T>* cur = new ListNode<T>;
			ListNode<T>* npos = pos.m_pos;

			cur->m_val = val;

			cur->m_prev = npos->m_prev;
			cur->m_prev->m_next = cur;

			cur->m_next = npos;
			npos->m_prev = cur;

			return cur;
		}

		iterator erase(iterator pos){
			ListNode<T>* npos = pos.m_pos;
			ListNode<T>* res = npos->m_next;

			npos->m_next->m_prev = npos->m_prev;
			npos->m_prev->m_next = npos->m_next;

			delete npos;
			return res;

		}

		iterator erase(iterator start, iterator finish){
			iterator i;
			for (i = start; i != end; ++i){
				erase(i);
			}
			return finish;

		}

		iterator begin(){
			return m_head->m_next;
		}
		iterator end(){
			return m_head;
		}
	};
}