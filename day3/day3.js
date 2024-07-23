console.log("Hello Worldd")
let x = 6;
let n = 3;
let z = x + n;
let c = `Hello " " ' ' Word`;
console.log(c);
console.log('c = ',c , `hello word''`, 'z = ', z);
console.log(typeof z);
let a = [5,5,9,10,11,2,1];
function swap(arr , index1 , index2){
    let temp = arr[index2];
    arr[index2] = arr[index1];
    arr[index1] = temp;
}
for(let i = 0 ; i <a.length - 1 ; i++ ){
    for(let j = a.length -1 ; j > 0 ; j--){
        if(a[j] < a[j-1]){
            swap(a,j,j-1);
        }
    }
}
console.log(a);
function binarysearch(arr , n , x){
    let l = 0 , r = n - 1;
    while(l <= r){
        let mid = ( l+ r ) / 2;
        if(arr[mid] == x) return mid;
        else{
            if(arr[mid] < x){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
    }
    return -1;
}
console.log(binarysearch(a,a.length,5));