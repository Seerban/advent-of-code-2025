const fs = require('fs');

const inters = []; // intervals
let total = 0; // total available IDs

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
    else return; // only read intervals
  });
}

function getTotalArea() {
  for(inter of inters) {
    total += inter[1] - inter[0] + 1;
  }
}

function removeOverlap() {
  // subtract overlap
  for(let i = 0; i < inters.length; i++) {
    for(let j = i+1; j < inters.length; j++) {
      if( inters[j][0] == -1 ) continue; // cleared intervals
      // check if intervals are NOT overlapping (inters is sorted)
      if( inters[i][1] < inters[j][0] ) continue;
      // check if one interval is inside the other, 
      if( inters[i][1] >= inters[j][1] ) {
        total -= inters[j][1] - inters[j][0] + 1;
        inters[j][0] = -1;
        inters[j][1] = -1;
      }
      else {
        total -= inters[i][1] - inters[j][0] + 1;
        inters[j][0] = inters[i][1] + 1; // cut the interval until no overlap
      }
    }
  }
}

readLines();
getTotalArea();
// sort by start of interval
inters.sort((a, b) => { return a[0] - b[0]; })
removeOverlap();
console.log( total );