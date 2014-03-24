#ifndef __MAPT_HPP__
#define __MAPT_HPP__

#include <iostream>
#include <map>
#include "Mutex.h"

template <typename T, typename M>
class MapT {
public :
        typedef std::map<T, M>                          value_type;
        typedef std::pair<T, M>                         pair_type;
        typedef typename std::map<T, M>::iterator       iterator;
        typedef typename std::map<T, M>::const_iterator const_iterator;

        template <typename _K> inline M 
        get_obj_by_key(_K key) {
                MutexLockGuard guard (m_mutex);
                iterator it = map_.find(key);
                return map_.end()!=it ? it->second : NULL;
        }

        template <typename _F> inline M
        get_obj_by_other(_F _pred) {
                MutexLockGuard guard (m_mutex);
                iterator it = find_if(map_.begin(), map_.end(), _pred);
                return map_.end()!=it ? it->second : NULL;
        }

        template <typename _First, typename _Second> inline bool
        insert(_First _first, _Second _second) {
                MutexLockGuard guard (m_mutex);
                return (map_.insert(std::make_pair<_First, _Second>(_first, _second))).second;
        }

        template <typename _K> inline M
        erase_by_key(_K key) {
                MutexLockGuard guard (m_mutex);
                iterator it = map_.find(key);
                if (map_.end() != it) {
                        map_.erase(it);
                        return it->second;
                } else {
                        return NULL;
                }
        }

        template <typename _F> inline M
        erase_by_other(_F _pred) {
                MutexLockGuard guard (m_mutex);
                iterator it = map_.find_if(map_.begin(), map_.end(), _pred);
                if (map_.end() != it) {
                        map_.rease(it);
                        return it->second;
                } else {
                        return NULL;
                }
        }

        template <typename _F> inline _F
        my_for_each(_F _pred) {
                MutexLockGuard guard (m_mutex);
                return for_each(map_.begin(), map_.end(), _pred);
        }

        value_type& get_obj(void) { return map_; }

private :
        MutexLock   m_mutex;
        value_type map_;
};

#endif // __MAPT_HPP__
