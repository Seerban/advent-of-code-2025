const fs = require('fs');

const inters = []; // intervals
const ingredients = []; // indexes to check
let fresh_count = 0;

const data = fs.readFileSync("input.txt", 'utf8');
const lines = data.split('\n');

function readLines() {
  lines.forEach(line => {
    nums = line.trim().split('-');
    
    if (nums.length == 2) {
      let a = parseInt(nums[0]);
      let b = parseInt(nums[1]);
      inters.push([a, b]);
    }
    else if(nums[0].length > 0)
        ingredients.push( parseInt(nums[0]) );
  });
}

function countFresh() {
  ingredients.forEach(id => {
    let fresh = false

    for(let i = 0; i < inters.length; i++)
      if(id >= inters[i][0] && id <= inters[i][1]) {
        fresh = true;
        break;
      }
    
    fresh_count += fresh ? 1 : 0;
  });
}

readLines();
countFresh();
console.log( fresh_count );