const int MAX_SLOT_NAME_LENGTH = 256;

static ArrayList nameArray;

void SlotName_init() {
  nameArray = new ArrayList(MAX_SLOT_NAME_LENGTH + 1);
}

SlotID SlotName_find(const char[] name) {
  return view_as<SlotID>(nameArray.FindString(name));
}

void SlotName_set(SlotID slotID, const char[] name) {
  int length = nameArray.Length;
  if (slotID > length) {
    nameArray.Resize(slotID + 1);
    for (int i = length; i <= slotID; ++i) {
      nameArray.SetString(i, "");
    }
  }
  nameArray.SetString(slotID, name);
}

void SlotName_get(SlotID slotID, char[] buffer, int length) {
  nameArray.GetString(slotID, buffer, length);
}

SlotID SlotName_createSlot(const char[] name) {
  if (SlotName_find(name) != SlotID_Invalid) {
    return SlotID_Invalid;
  }

  SlotID slotID = SlotManager_createSlot();
  SlotName_set(slotID, name);

  return slotID;
}