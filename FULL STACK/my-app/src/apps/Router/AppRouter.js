import React from 'react';
import { BrowserRouter, Routes, Route, Link } from 'react-router-dom';
import Home from './Home';
import About from './About';

export default function AppRouter() {
  return (
    <div>
      <BrowserRouter>
        <h1>React Routing Examples style style</h1>
        <span>
          <Link to="/home">Home</Link> | <Link to="/about">About</Link>
        </span>

        <Routes>
          <Route path="/home" element={<Home />} />
          <Route path="/About" element={<About />} />
        </Routes>
      </BrowserRouter>
    </div>
  );
}
