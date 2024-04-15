
#include "SetMessageModificationToGalileoCNav.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetMessageModificationToGalileoCNav
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetMessageModificationToGalileoCNav::CmdName = "SetMessageModificationToGalileoCNav";
    const char* const SetMessageModificationToGalileoCNav::Documentation = "Set (or Modify) event to change Galileo C/NAV message bits. If you send this command without setting the ID\n"
      "parameter, or if you set the ID with a value never used before, a new Modification event will be\n"
      "created. If you reuse the same event ID, it will modify the existing event.\n"
      "\n"
      "Note that start and stop time are automatically extended to beginning and ending of overlapped\n"
      "messages.\n"
      "\n"
      "BitModifications can be an empty string. The Modification will have no effect until you modify it with at\n"
      "least one bits mod.\n"
      "\n"
      "A bits mod is represented with a string using the following format: \"I:Bits\" where I is a bit\n"
      "index (1 refers to the first transmitted bit) and Bits is a modification mask where each\n"
      "character describes a modification to a single bit. The allowed characters are:\n"
      "   0 : force bit to 0\n"
      "   1 : force bit to 1\n"
      "   - : leave bit unchanged\n"
      "   X : revert bit (0 becomes 1 and 1 becomes 0)\n"
      "\n"
      "For example: \"24:X---10XX\" will: revert bits 24, 30 and 31\n"
      "                 set bit 28 to 1\n"
      "                 set bit 29 to 0\n"
      "The other bits are not affected.\n"
      "\n"
      "You can add multiple bit modifications using commas. For example: \"24:X---10XX,127:100X,231:01\"\n"
      "\n"
      "Name             Type         Description\n"
      "---------------- ------------ -------------------------------------------------------------------------------------\n"
      "SignalArray      array string Array of signals to apply the message modification to, accepts \"E6BC\" (empty for all)\n"
      "SvId             int          The satellite's SV ID 1..36 (use 0 to apply modification to all SVs)\n"
      "StartTime        int          Elapsed time in seconds since start of simulation\n"
      "StopTime         int          Elapsed time in seconds since start of simulation (use 0 for no stop time)\n"
      "UpdateCRC        bool         Recalculate CRC after making modification\n"
      "BitModifications string       Comma separated bit modifications\n"
      "Id               string       Unique identifier of the event";
    const char* const SetMessageModificationToGalileoCNav::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetMessageModificationToGalileoCNav);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetMessageModificationToGalileoCNav);


    SetMessageModificationToGalileoCNav::SetMessageModificationToGalileoCNav()
      : CommandBase(CmdName, TargetId)
    {}

    SetMessageModificationToGalileoCNav::SetMessageModificationToGalileoCNav(const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, bool updateCRC, const std::string& bitModifications, const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setSignalArray(signalArray);
      setSvId(svId);
      setStartTime(startTime);
      setStopTime(stopTime);
      setUpdateCRC(updateCRC);
      setBitModifications(bitModifications);
      setId(id);
    }

    SetMessageModificationToGalileoCNavPtr SetMessageModificationToGalileoCNav::create(const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, bool updateCRC, const std::string& bitModifications, const std::string& id)
    {
      return std::make_shared<SetMessageModificationToGalileoCNav>(signalArray, svId, startTime, stopTime, updateCRC, bitModifications, id);
    }

    SetMessageModificationToGalileoCNavPtr SetMessageModificationToGalileoCNav::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetMessageModificationToGalileoCNav>(ptr);
    }

    bool SetMessageModificationToGalileoCNav::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::string>>::is_valid(m_values["SignalArray"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<int>::is_valid(m_values["StartTime"])
          && parse_json<int>::is_valid(m_values["StopTime"])
          && parse_json<bool>::is_valid(m_values["UpdateCRC"])
          && parse_json<std::string>::is_valid(m_values["BitModifications"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string SetMessageModificationToGalileoCNav::documentation() const { return Documentation; }

    const std::vector<std::string>& SetMessageModificationToGalileoCNav::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SignalArray", "SvId", "StartTime", "StopTime", "UpdateCRC", "BitModifications", "Id"}; 
      return names; 
    }


    int SetMessageModificationToGalileoCNav::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    std::vector<std::string> SetMessageModificationToGalileoCNav::signalArray() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["SignalArray"]);
    }

    void SetMessageModificationToGalileoCNav::setSignalArray(const std::vector<std::string>& signalArray)
    {
      m_values.AddMember("SignalArray", parse_json<std::vector<std::string>>::format(signalArray, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetMessageModificationToGalileoCNav::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetMessageModificationToGalileoCNav::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetMessageModificationToGalileoCNav::startTime() const
    {
      return parse_json<int>::parse(m_values["StartTime"]);
    }

    void SetMessageModificationToGalileoCNav::setStartTime(int startTime)
    {
      m_values.AddMember("StartTime", parse_json<int>::format(startTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetMessageModificationToGalileoCNav::stopTime() const
    {
      return parse_json<int>::parse(m_values["StopTime"]);
    }

    void SetMessageModificationToGalileoCNav::setStopTime(int stopTime)
    {
      m_values.AddMember("StopTime", parse_json<int>::format(stopTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetMessageModificationToGalileoCNav::updateCRC() const
    {
      return parse_json<bool>::parse(m_values["UpdateCRC"]);
    }

    void SetMessageModificationToGalileoCNav::setUpdateCRC(bool updateCRC)
    {
      m_values.AddMember("UpdateCRC", parse_json<bool>::format(updateCRC, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetMessageModificationToGalileoCNav::bitModifications() const
    {
      return parse_json<std::string>::parse(m_values["BitModifications"]);
    }

    void SetMessageModificationToGalileoCNav::setBitModifications(const std::string& bitModifications)
    {
      m_values.AddMember("BitModifications", parse_json<std::string>::format(bitModifications, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetMessageModificationToGalileoCNav::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetMessageModificationToGalileoCNav::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
