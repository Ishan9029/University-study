import React from 'react';
import Student from './Student';

const App = () => {
  return (
    <div>
      <h1>Student List</h1>
      <Student name="Ishan" grade="A" />
      <Student name="Rishabh" grade="B" />
      <Student name="Girish" grade="A" />
      <Student name="Chiranjiv" grade="A" />
    </div>
  );
};
export default App;
