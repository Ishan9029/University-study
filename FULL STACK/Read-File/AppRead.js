const fs = require('fs');
const EventEmitter = require('events');

// Create a new EventEmitter instance
const emitter = new EventEmitter();

// Listener for 'fileReadDone' event
emitter.on('fileReadDone', (fileContent) => {
  try {
    const students = JSON.parse(fileContent);

    console.log('Student Details:\n');
    students.forEach((student) => {
      console.log(`ID: ${student.id}`);
      console.log(`Name: ${student.name}`);
      console.log(`Age: ${student.age}`);
      console.log(`Course: ${student.course}`);
      console.log('----------------------');
    });
  } catch (err) {
    console.error('Error parsing JSON:', err);
  }
});

// Read the JSON file asynchronously
fs.readFile('Student.json', 'utf8', (err, data) => {
  if (err) {
    console.error('Error reading file:', err);
    return;
  }

  // Emit custom event with file content
  emitter.emit('fileReadDone', data);
});
