
#include "GetDektecSerialNumberAssignation.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetDektecSerialNumberAssignation
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetDektecSerialNumberAssignation::CmdName = "GetDektecSerialNumberAssignation";
    const char* const GetDektecSerialNumberAssignation::Documentation = "Get  the Dektec serial number assignation for a Dektec type, indexed by device number.\n"
      "\n"
      "Name       Type   Description\n"
      "---------- ------ --------------------------------------------------------\n"
      "DektecType string Dektec type, valid values are \"DTA-2115B\" or \"DTA-2116\".";
    const char* const GetDektecSerialNumberAssignation::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetDektecSerialNumberAssignation);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetDektecSerialNumberAssignation);


    GetDektecSerialNumberAssignation::GetDektecSerialNumberAssignation()
      : CommandBase(CmdName, TargetId)
    {}

    GetDektecSerialNumberAssignation::GetDektecSerialNumberAssignation(const std::string& dektecType)
      : CommandBase(CmdName, TargetId)
    {

      setDektecType(dektecType);
    }

    GetDektecSerialNumberAssignationPtr GetDektecSerialNumberAssignation::create(const std::string& dektecType)
    {
      return std::make_shared<GetDektecSerialNumberAssignation>(dektecType);
    }

    GetDektecSerialNumberAssignationPtr GetDektecSerialNumberAssignation::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetDektecSerialNumberAssignation>(ptr);
    }

    bool GetDektecSerialNumberAssignation::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["DektecType"])
        ;

    }

    std::string GetDektecSerialNumberAssignation::documentation() const { return Documentation; }

    const std::vector<std::string>& GetDektecSerialNumberAssignation::fieldNames() const 
    { 
      static const std::vector<std::string> names {"DektecType"}; 
      return names; 
    }


    int GetDektecSerialNumberAssignation::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetDektecSerialNumberAssignation::dektecType() const
    {
      return parse_json<std::string>::parse(m_values["DektecType"]);
    }

    void GetDektecSerialNumberAssignation::setDektecType(const std::string& dektecType)
    {
      setValue("DektecType", parse_json<std::string>::format(dektecType, m_values.GetAllocator()));
    }


  }
}
