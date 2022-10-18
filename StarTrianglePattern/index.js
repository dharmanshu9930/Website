function box(length) {
    let result = '';
    for (let i = 0; i < length; i++) {
        for (let j = 0; j < length; j++) {
            result += '* ';
        }
        result += '\n';
    }
    return result;
}
console.log(box(10));
