def add_to_sheet(values, google_sheet_id, sheet_name):
    """
    This method is used to insert value in to Google Sheet considering you know the Sheet Name and ID.
    values(Nested List)
    google_sheet_id: ID of Google SHeet you want to insert into.
    sheet_name: Name of the sheet inside your requested google Sheet.
    """
    
    SERVICE_ACCOUNT_FILE = <Path to Credentials File>

    SCOPES = ["https://www.googleapis.com/auth/spreadsheets","https://www.googleapis.com/auth/drive.file", "https://www.googleapis.com/auth/drive"]

    credentials = service_account.Credentials.from_service_account_file(SERVICE_ACCOUNT_FILE, scopes=SCOPES)

    service = discovery.build('sheets', 'v4', credentials=credentials)
    drive_api = build('drive', 'v3', credentials=credentials)
 
    no_of_row = len(values)
    no_of_col = len(values[0][0])
    if no_of_col <= 26:
        ranges = sheet_name + "!A1:" + chr(ord('A') + no_of_col) + str(no_of_row)
    else:
        ranges = sheet_name + "!A1:A" + chr(ord('A') + no_of_col - 26) + str(no_of_row)

    body = {"values": values}
    # clear sheet
    service.spreadsheets().values().clear(spreadsheetId=google_sheet_id, 
        range='{0}!A1:Z'.format(sheet_name), body={}).execute()
    result = (
        service.spreadsheets()
        .values()
        .update(
            spreadsheetId=google_sheet_id,
            range=ranges,
            valueInputOption="USER_ENTERED",
            body=body,
        )
        .execute()
    )
    
    return result
