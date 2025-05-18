import React, { useState, useEffect } from 'react';

// This is for dynamic imports
const modules = import.meta.glob('./apps/**/*App*.jsx', { eager: true });

function App() {
  const [components, setComponents] = useState({});
  const [selected, setSelected] = useState('');

  useEffect(() => {
    console.log('Modules loaded:', modules);

    const loadComponents = async () => {
      const loaded = {};
      for (const path in modules) {
        const module = modules[path]; // Eager load (no async needed)
        const nameMatch = path.match(/App(\w+)\.jsx$/);
        if (nameMatch) {
          const name = `App${nameMatch[1]}`;
          loaded[name] = module.default;
          console.log('Loaded:', name);
        }
      }
      setComponents(loaded);
      setSelected(Object.keys(loaded)[0]); // Default to the first component
    };
    loadComponents();
  }, []);

  const SelectedComponent = components[selected];

  return (
    <div>
      <h2>Select an App</h2>
      <select onChange={(e) => setSelected(e.target.value)} value={selected}>
        {Object.keys(components).map((key) => (
          <option key={key} value={key}>
            {key}
          </option>
        ))}
      </select>

      <div style={{ marginTop: '20px' }}>
        {SelectedComponent ? <SelectedComponent /> : <p>Loading...</p>}
      </div>
    </div>
  );
}

export default App;
