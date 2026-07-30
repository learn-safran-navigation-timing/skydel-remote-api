
#include "SetDektecSerialNumberAssignation.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetDektecSerialNumberAssignation
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetDektecSerialNumberAssignation::CmdName = "SetDektecSerialNumberAssignation";
    const char* const SetDektecSerialNumberAssignation::Documentation = "Set  the Dektec serial number assignation for a Dektec type, indexed by device number.\n"
      "\n"
      "Name          Type         Description\n"
      "------------- ------------ --------------------------------------------------------\n"
      "DektecType    string       Dektec type, valid values are \"DTA-2115B\" or \"DTA-2116\".\n"
      "SerialNumbers array string Dektec Serial Numbers";
    const char* const SetDektecSerialNumberAssignation::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetDektecSerialNumberAssignation);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetDektecSerialNumberAssignation);


    SetDektecSerialNumberAssignation::SetDektecSerialNumberAssignation()
      : CommandBase(CmdName, TargetId)
    {}

    SetDektecSerialNumberAssignation::SetDektecSerialNumberAssignation(const std::string& dektecType, const std::vector<std::string>& serialNumbers)
      : CommandBase(CmdName, TargetId)
    {

      setDektecType(dektecType);
      setSerialNumbers(serialNumbers);
    }

    SetDektecSerialNumberAssignationPtr SetDektecSerialNumberAssignation::create(const std::string& dektecType, const std::vector<std::string>& serialNumbers)
    {
      return std::make_shared<SetDektecSerialNumberAssignation>(dektecType, serialNumbers);
    }

    SetDektecSerialNumberAssignationPtr SetDektecSerialNumberAssignation::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetDektecSerialNumberAssignation>(ptr);
    }

    bool SetDektecSerialNumberAssignation::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["DektecType"])
          && parse_json<std::vector<std::string>>::is_valid(m_values["SerialNumbers"])
        ;

    }

    std::string SetDektecSerialNumberAssignation::documentation() const { return Documentation; }

    const std::vector<std::string>& SetDektecSerialNumberAssignation::fieldNames() const 
    { 
      static const std::vector<std::string> names {"DektecType", "SerialNumbers"}; 
      return names; 
    }


    int SetDektecSerialNumberAssignation::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetDektecSerialNumberAssignation::dektecType() const
    {
      return parse_json<std::string>::parse(m_values["DektecType"]);
    }

    void SetDektecSerialNumberAssignation::setDektecType(const std::string& dektecType)
    {
      setValue("DektecType", parse_json<std::string>::format(dektecType, m_values.GetAllocator()));
    }



    std::vector<std::string> SetDektecSerialNumberAssignation::serialNumbers() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["SerialNumbers"]);
    }

    void SetDektecSerialNumberAssignation::setSerialNumbers(const std::vector<std::string>& serialNumbers)
    {
      setValue("SerialNumbers", parse_json<std::vector<std::string>>::format(serialNumbers, m_values.GetAllocator()));
    }


  }
}
