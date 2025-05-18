import React from 'react';
import { BrowserRouter, Routes, Route } from 'react-router-dom';
import Home from './Login';
import About from './User';

export default function AppNavigate() {
  return (
    <div>
      <BrowserRouter>
        <h1>React Routing Examples</h1>
        <Routes>
          <Route path="/" element={<Home />} />
          <Route path="/About" element={<About />} />
        </Routes>
      </BrowserRouter>
    </div>
  );
}
