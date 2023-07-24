function convertAllDocsToPDF() {
  '''
    This function is convert all the Google Docs 
    in the given Google Drive Folder into PDF Format.
    These Docs get saved in the designated Google Drive Folder.
  '''
  try {
    var folderId = "Drive_Folder_ID"; // Replace with the ID of the folder containing the Google Docs documents.
    var folder = DriveApp.getFolderById(folderId);
    var files = folder.getFilesByType(MimeType.GOOGLE_DOCS);
    
    while (files.hasNext()) {
      var file = files.next();
      var docId = file.getId();
      var pdfFile = DriveApp.getFileById(docId).getAs('application/pdf');
      var pdfName = file.getName() + ".pdf";
      
      folder.createFile(pdfFile).setName(pdfName);
      
      Logger.log("PDF created for: " + file.getName());
    }
    
    Logger.log("All documents converted successfully.");
  } catch (e) {
    Logger.log("Error converting documents to PDF: " + e);
  }
}
