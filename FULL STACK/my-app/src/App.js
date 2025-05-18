import React, { useState, Suspense, lazy } from 'react';
import './App.css';
// Recursively find all files matching App*.js in the ./apps folder
const apps = require.context('./apps', true, /App.*\.js$/);

// Create a map of path strings to lazy-loaded components
const appComponents = apps.keys().reduce((acc, path) => {
  const cleanedPath = path.replace('./', '');
  acc[cleanedPath] = lazy(() => import(`./apps/${cleanedPath}`));
  return acc;
}, {});

function App() {
  const [selectedApp, setSelectedApp] = useState('');

  const handleChange = (e) => {
    setSelectedApp(e.target.value);
  };

  const SelectedComponent = selectedApp ? appComponents[selectedApp] : null;

  return (
    <div style={{ textAlign: 'center', padding: '2rem' }}>
      <h1>Main App</h1>

      <select onChange={handleChange} value={selectedApp}>
        <option value="">-- Select an App --</option>
        {Object.keys(appComponents).map((key) => (
          <option key={key} value={key}>
            {key.split('/').pop().replace('.js', '')}
          </option>
        ))}
      </select>

      <div style={{ marginTop: '2rem' }}>
        <Suspense fallback={<div>Loading app...</div>}>
          {SelectedComponent && <SelectedComponent />}
        </Suspense>
      </div>
    </div>
  );
}

export default App;
