const express = require('express');
const app = express();
const port = 3000;

app.use(express.json());

let items = [{ id: 1, name: 'Item 1' }];

// ✅ Root route
app.get('/', (req, res) => {
  res.send('Welcome to the Express Server!');
});

// GET all items
app.get('/items', (req, res) => {
  res.json(items);
});

// POST new item
app.post('/items', (req, res) => {
  const newItem = { id: Date.now(), name: req.body.name };
  items.push(newItem);
  res.status(201).json(newItem);
});

// PUT update item
app.put('/items/:id', (req, res) => {
  const id = parseInt(req.params.id);
  const index = items.findIndex((item) => item.id === id);
  if (index !== -1) {
    items[index].name = req.body.name;
    res.json(items[index]);
  } else {
    res.status(404).json({ message: 'Item not found' });
  }
});

// DELETE item
app.delete('/items/:id', (req, res) => {
  const id = parseInt(req.params.id);
  items = items.filter((item) => item.id !== id);
  res.json({ message: 'Item deleted' });
});

app.listen(port, () => {
  console.log(`Server is running on http://localhost:${port}`);
});
