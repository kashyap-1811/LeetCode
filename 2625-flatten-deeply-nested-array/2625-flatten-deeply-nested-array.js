/**
 * @param {Array} arr
 * @param {number} depth
 * @return {Array}
 */

 var recurse = function(arr, n, depth, ans) {
    for (let i = 0; i < arr.length; i++) {
        if (Array.isArray(arr[i]) && depth < n)
            recurse(arr[i], n, depth + 1, ans);
        else
            ans.push(arr[i]);
    }
 }

var flat = function (arr, n) {   
    if (n == 0)
        return arr;
        
    let ans = [];

    for (let i = 0; i < arr.length; i++) {
        if (Array.isArray(arr[i]))
            recurse(arr[i], n, 1, ans);
        else
            ans.push(arr[i]);
    }

    return ans;
};