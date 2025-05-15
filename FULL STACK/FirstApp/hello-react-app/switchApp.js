// switchApp.js
const fs = require('fs');
const path = require('path');

const args = process.argv.slice(2);
const folderName = args[0];

if (!folderName) {
  console.error(
    '❌ Please provide a folder name.\nExample: node switchApp USEEFFECT',
  );
  process.exit(1);
}

const appFilePath = path.join(__dirname, 'src', folderName, 'App.js');

if (!fs.existsSync(appFilePath)) {
  console.error(`❌ App.js not found in src/${folderName}/`);
  process.exit(1);
}

const appsFilePath = path.join(__dirname, 'src', 'apps.js');
const exportLine = `export { default } from './${folderName}/App';\n`;

fs.writeFileSync(appsFilePath, exportLine);

console.log(`✅ Switched to ${folderName}/App.js`);
