
#include "SetMessageModificationToGlonassNav.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetMessageModificationToGlonassNav
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetMessageModificationToGlonassNav::CmdName = "SetMessageModificationToGlonassNav";
    const char* const SetMessageModificationToGlonassNav::Documentation = "Set (or Modify) event to change GLONASS NAV message bits.\n"
      "\n"
      "Note that start and stop time are automatically extended to beginning and ending of overlapped\n"
      "message strings. The Modification parameter is a string where the first character applies to bit\n"
      "85 of frame string and last character applies to Hamming Code bit 1.\n"
      "   '0' will force bit to zero\n"
      "   '1' will for bit to one\n"
      "   'X' will negate bit value\n"
      "   ' ' white space are ignored (use them to separate the string into bytes to help reading)\n"
      "   '-' or any other byte value will have no effect\n"
      "\n"
      "Example:\n"
      "\n"
      "\"-0--- 1------- -------- -------- -------- -------- -------- -------- -------- -------- ---1--X-\"\n"
      "  |  |                                           |  |\n"
      "  |  +- Force bit 80 to '1'               Force Hamming code bit 5 to '1' -+  |\n"
      "  |                                               |\n"
      "  +------ Force bit 84 to 0                   Negate Hamming code bit 2 ----+\n"
      "\n"
      "Note: if UpdateHammingCode is true, any modification to bits 1..8 will have no effect.\n"
      "\n"
      "The ID parameter is automatically updated with a unique ID by the simulator for future reference.\n"
      "If the ID is set with a value other than an empty string, the simulator will try to find a match\n"
      "with previously added events. If there is a match, the event is updated with this message\n"
      "instead of adding a new event. If there is no match, the event is added and the ID is not\n"
      "changed.\n"
      "\n"
      "Name               Type         Description\n"
      "------------------ ------------ --------------------------------------------------------------------------------------------\n"
      "SignalArray        array string Array of signals to apply the message modification to, accepts \"G1\" and \"G2\" (empty for all)\n"
      "SvId               int          The satellite's SV ID number 1..24 (use 0 to apply modification to all SVs)\n"
      "StartTime          int          Elapsed time in seconds since start of simulation\n"
      "StopTime           int          Elapsed time in seconds since start of simulation (use 0 for no stop time)\n"
      "Frame              int          Frame 1..5 (use 0 to apply modification to all frames)\n"
      "StringNumber       int          String 1..15 (use 0 to apply modification to all strings)\n"
      "UpdateHammingCode  bool         Recalculate Hamming Code after making modification\n"
      "StringModification string       Modification string must be 85 bits long (or more if using white spaces)\n"
      "Id                 string       Unique identifier of the event";
    const char* const SetMessageModificationToGlonassNav::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetMessageModificationToGlonassNav);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetMessageModificationToGlonassNav);


    SetMessageModificationToGlonassNav::SetMessageModificationToGlonassNav()
      : CommandBase(CmdName, TargetId)
    {}

    SetMessageModificationToGlonassNav::SetMessageModificationToGlonassNav(const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int frame, int stringNumber, bool updateHammingCode, const std::string& stringModification, const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setSignalArray(signalArray);
      setSvId(svId);
      setStartTime(startTime);
      setStopTime(stopTime);
      setFrame(frame);
      setStringNumber(stringNumber);
      setUpdateHammingCode(updateHammingCode);
      setStringModification(stringModification);
      setId(id);
    }

    SetMessageModificationToGlonassNavPtr SetMessageModificationToGlonassNav::create(const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int frame, int stringNumber, bool updateHammingCode, const std::string& stringModification, const std::string& id)
    {
      return std::make_shared<SetMessageModificationToGlonassNav>(signalArray, svId, startTime, stopTime, frame, stringNumber, updateHammingCode, stringModification, id);
    }

    SetMessageModificationToGlonassNavPtr SetMessageModificationToGlonassNav::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetMessageModificationToGlonassNav>(ptr);
    }

    bool SetMessageModificationToGlonassNav::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::string>>::is_valid(m_values["SignalArray"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<int>::is_valid(m_values["StartTime"])
          && parse_json<int>::is_valid(m_values["StopTime"])
          && parse_json<int>::is_valid(m_values["Frame"])
          && parse_json<int>::is_valid(m_values["StringNumber"])
          && parse_json<bool>::is_valid(m_values["UpdateHammingCode"])
          && parse_json<std::string>::is_valid(m_values["StringModification"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string SetMessageModificationToGlonassNav::documentation() const { return Documentation; }

    const std::vector<std::string>& SetMessageModificationToGlonassNav::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SignalArray", "SvId", "StartTime", "StopTime", "Frame", "StringNumber", "UpdateHammingCode", "StringModification", "Id"}; 
      return names; 
    }


    int SetMessageModificationToGlonassNav::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    std::vector<std::string> SetMessageModificationToGlonassNav::signalArray() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["SignalArray"]);
    }

    void SetMessageModificationToGlonassNav::setSignalArray(const std::vector<std::string>& signalArray)
    {
      m_values.AddMember("SignalArray", parse_json<std::vector<std::string>>::format(signalArray, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetMessageModificationToGlonassNav::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetMessageModificationToGlonassNav::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetMessageModificationToGlonassNav::startTime() const
    {
      return parse_json<int>::parse(m_values["StartTime"]);
    }

    void SetMessageModificationToGlonassNav::setStartTime(int startTime)
    {
      m_values.AddMember("StartTime", parse_json<int>::format(startTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetMessageModificationToGlonassNav::stopTime() const
    {
      return parse_json<int>::parse(m_values["StopTime"]);
    }

    void SetMessageModificationToGlonassNav::setStopTime(int stopTime)
    {
      m_values.AddMember("StopTime", parse_json<int>::format(stopTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetMessageModificationToGlonassNav::frame() const
    {
      return parse_json<int>::parse(m_values["Frame"]);
    }

    void SetMessageModificationToGlonassNav::setFrame(int frame)
    {
      m_values.AddMember("Frame", parse_json<int>::format(frame, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetMessageModificationToGlonassNav::stringNumber() const
    {
      return parse_json<int>::parse(m_values["StringNumber"]);
    }

    void SetMessageModificationToGlonassNav::setStringNumber(int stringNumber)
    {
      m_values.AddMember("StringNumber", parse_json<int>::format(stringNumber, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetMessageModificationToGlonassNav::updateHammingCode() const
    {
      return parse_json<bool>::parse(m_values["UpdateHammingCode"]);
    }

    void SetMessageModificationToGlonassNav::setUpdateHammingCode(bool updateHammingCode)
    {
      m_values.AddMember("UpdateHammingCode", parse_json<bool>::format(updateHammingCode, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetMessageModificationToGlonassNav::stringModification() const
    {
      return parse_json<std::string>::parse(m_values["StringModification"]);
    }

    void SetMessageModificationToGlonassNav::setStringModification(const std::string& stringModification)
    {
      m_values.AddMember("StringModification", parse_json<std::string>::format(stringModification, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetMessageModificationToGlonassNav::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetMessageModificationToGlonassNav::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
