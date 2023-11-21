function populateDocument() {
    '''
    This function is to fetch the data from Google Sheet 
    and create Google Docs by populating the data from the sheet.
    These Docs get saved in the designated Google Drive Folder.
    '''
  var folderId = 'Drive_Folder_ID'; // Replace with the ID of the folder where you want to save the documents
  var sheet = SpreadsheetApp.openById('Sheet_ID');
  var data = sheet.getSheets()[0].getDataRange().getValues();
  var templateDocId = 'Google Docs Template ID';
  var templateDoc = DriveApp.getFileById(templateDocId);

  // Assuming the first row in the sheet contains headers
  var headers = data[0];

  for (var i = 1; i < data.length; i++) {
    var rowData = data[i];
    var newDocName = rowData[0]+'_' + rowData[1];
    var newDocFile = templateDoc.makeCopy(newDocName, DriveApp.getFolderById(folderId));
    var newDoc = DocumentApp.openById(newDocFile.getId());
    var newHeader = newDoc.getHeader();
    var newFooter = newDoc.getFooter();
    var newBody = newDoc.getBody();

    // Replace placeholders in the new document with data from the sheet
    for (var j = 0; j < headers.length; j++) {
      var placeholder = '{{' + headers[j] + '}}';
      var value = rowData[j];
      replacePlaceholders(newBody, placeholder, value);
      replacePlaceholders(newHeader, placeholder, value);
      replacePlaceholders(newFooter, placeholder, value);
    }

    // Save and close the new document
    newDoc.saveAndClose();
  }
}

// Function to replace placeholders in the document section (header, footer, or body)
function replacePlaceholders(section, placeholder, value) {
  var searchResult = section.findText(placeholder);
  while (searchResult) {
    var foundText = searchResult.getElement().asText();
    foundText.setText(foundText.getText().replace(placeholder, value));
    searchResult = section.findText(placeholder, searchResult);
  }
}