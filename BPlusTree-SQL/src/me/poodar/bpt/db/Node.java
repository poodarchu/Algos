package me.poodar.bpt.db;

import java.util.Arrays;

/**
 * Created by poodar on 6/13/16.
 */

/**
 * leaf node 用于保存数据entry(相当于record),entry的形式是(key,value)。
 * 所有的leaf node也被组织成链表的形式。
 * leaf node的抽象定义是:
 * struct leafNode {
 *     vector<Key> keys;
 *     vector<Value> values;
 *     PagePointer nextPage;
 * }
 * 对任意的leaf node: p
 * p.keys.size() == p.values.size()
 */

/**
 * Interior node被组织称一个树的形式,从root node(根节点,也是一个interior node)开始,
 * 通过保存一系列的key,来加速查询leaf node
 * Interior node保存着一系列的key和page指针
 * interiorNode的抽象定义:
 * struct {
 *     vector<Key> keys;
 *     vector<PagePointer> pointers;
 * }
 * 对任意的interior node来说:
 * p.keys.size() + 1 == p.pointers.size()
 *
 * Neighboring pointer:
 * 对于一个ki,before(ki)是ki前面临近的指针,after(ki)是ki后面临近的指针:
 * p.before(ki) == p.pointers[i];
 * p.after(ki) == p.pointers[i+1;
 */

/**
 * B+树的属性和约束条件
 * 1. node中的key都是排好序的。
 *    假设，p是B+树中的node，那么我们必须维持p.keys关于value是有序的。
 *
 * 2. 各个node之间也是按key进行排序的。
 *    B+树是有序树，表现在一下几个方面：
 *     A) leaf node是有序的：
 *        ∀p∈LeafNode,∀k∈p.keys,∀k′∈p.next_page.keys,k<k′
 *        多个leaf node组成一个有序链表，在各个leaf node之间使得高效的对(key, value)遍历成为可能。
 *     B) interior node是有序的：
 *        B+树对所有的key k，和其临近的指针after(k) 、after(k)，满足下面的条件：
 *          k>max(keys(before(k)))
 *          k≤min(keys(after(k)))
 *    换句话说，k是介于before(k)、after(k) 的key之间的key。
 *
 * 3.  B+树是平衡树
 *     B+树是平衡树，所有从root node到任何leaf node的路径长度是相等的。
 *
 * 4. B+树node是充分填充的
 *    B+树允许它的node部分填充。主要是设计了一个填充因子的参数，用来限定每个non-root node（非根节点）的最小填充度。
 *    如果一个non-root node的填充度不够，我们就说该node underflow，在B+树里只有root node可以underflow。
 */
public class Node {
    int keys[] = new int[3];
    String tuple[] = new String[1];

    Node first, second, third, fourth;
    int counter;
    Node parentNode;

    public Node() {
        counter = 0;
        first = null;
        second = null;
        third = null;
        fourth = null;
        parentNode = null;
        tuple[0] = "";
    }

    public boolean isFull() {
        if(counter == 3)
            return true;
        return false;
    }

    public int getCounter() {
        return counter;
    }

    public void increament() {
        counter++;
    }

    public void setCounter (int counter) {
        this.counter = counter;
    }

    public int[] getKeys() {
        return keys;
    }

    public void setKeys(int[] keys) {
        this.keys = Arrays.copyOf(keys, 3);
    }

    public String[] getTuple() {
        return tuple;
    }

    public Node getFirst() {
        return first;
    }

    public void setFirst(Node first) {
        this.first = first;
    }

    public Node getSecond() {
        return second;
    }

    public void setSecond(Node second) {
        this.second = second;
    }

    public Node getThird() {
        return third;
    }

    public void setThird(Node third) {
        this.third = third;
    }

    public Node getFourth() {
        return fourth;
    }

    public void setFourth(Node fourth) {
        this.fourth = fourth;
    }

























}
