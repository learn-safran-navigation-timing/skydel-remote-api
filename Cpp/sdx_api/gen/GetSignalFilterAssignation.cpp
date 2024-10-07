
#include "GetSignalFilterAssignation.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSignalFilterAssignation
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSignalFilterAssignation::CmdName = "GetSignalFilterAssignation";
    const char* const GetSignalFilterAssignation::Documentation = "Returns filter names assigned to requested signals.\n"
      "\n"
      "Name        Type         Description\n"
      "----------- ------------ --------------------------------------------------------------------------------\n"
      "SignalArray array string An array of signals.\n"
      "                         Accepted values are: \"L1CA\", \"L1C\", \"L1P\", \"L1ME\", \"L1MR\", \"L2C\", \"L2P\", \"L2ME\",\n"
      "                                              \"L2MR\", \"L5\", \"G1\", \"G2\", \"E1\", \"E1PRS\", \"E5a\", \"E5b\",\n"
      "                                              \"E5AltBOC\", \"E6BC\", \"E6PRS\", \"B1\", \"B2\", \"B1C\", \"B2a\",\n"
      "                                              \"B3I\", \"SBASL1\", \"SBASL5\", \"QZSSL1CA\", \"QZSSL1CB\",\n"
      "                                              \"QZSSL1C\", \"QZSSL2C\", \"QZSSL5\", \"QZSSL1S\", \"QZSSL5S\",\n"
      "                                              \"QZSSL6\", \"NAVICL1\", \"NAVICL5\", \"NAVICS\" and \"PULSARXL\"";
    const char* const GetSignalFilterAssignation::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetSignalFilterAssignation);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetSignalFilterAssignation);


    GetSignalFilterAssignation::GetSignalFilterAssignation()
      : CommandBase(CmdName, TargetId)
    {}

    GetSignalFilterAssignation::GetSignalFilterAssignation(const std::vector<std::string>& signalArray)
      : CommandBase(CmdName, TargetId)
    {

      setSignalArray(signalArray);
    }

    GetSignalFilterAssignationPtr GetSignalFilterAssignation::create(const std::vector<std::string>& signalArray)
    {
      return std::make_shared<GetSignalFilterAssignation>(signalArray);
    }

    GetSignalFilterAssignationPtr GetSignalFilterAssignation::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSignalFilterAssignation>(ptr);
    }

    bool GetSignalFilterAssignation::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::string>>::is_valid(m_values["SignalArray"])
        ;

    }

    std::string GetSignalFilterAssignation::documentation() const { return Documentation; }

    const std::vector<std::string>& GetSignalFilterAssignation::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SignalArray"}; 
      return names; 
    }


    int GetSignalFilterAssignation::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::vector<std::string> GetSignalFilterAssignation::signalArray() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["SignalArray"]);
    }

    void GetSignalFilterAssignation::setSignalArray(const std::vector<std::string>& signalArray)
    {
      m_values.AddMember("SignalArray", parse_json<std::vector<std::string>>::format(signalArray, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
