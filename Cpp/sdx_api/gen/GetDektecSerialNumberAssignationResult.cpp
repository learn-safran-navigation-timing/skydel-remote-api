
#include "GetDektecSerialNumberAssignationResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetDektecSerialNumberAssignationResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetDektecSerialNumberAssignationResult::CmdName = "GetDektecSerialNumberAssignationResult";
    const char* const GetDektecSerialNumberAssignationResult::Documentation = "Result of GetDektecSerialNumberAssignation.\n"
      "\n"
      "Name          Type         Description\n"
      "------------- ------------ --------------------------------------------------------\n"
      "DektecType    string       Dektec type, valid values are \"DTA-2115B\" or \"DTA-2116\".\n"
      "SerialNumbers array string Dektec Serial Numbers";
    const char* const GetDektecSerialNumberAssignationResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetDektecSerialNumberAssignationResult);


    GetDektecSerialNumberAssignationResult::GetDektecSerialNumberAssignationResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetDektecSerialNumberAssignationResult::GetDektecSerialNumberAssignationResult(const std::string& dektecType, const std::vector<std::string>& serialNumbers)
      : CommandResult(CmdName, TargetId)
    {

      setDektecType(dektecType);
      setSerialNumbers(serialNumbers);
    }

    GetDektecSerialNumberAssignationResult::GetDektecSerialNumberAssignationResult(CommandBasePtr relatedCommand, const std::string& dektecType, const std::vector<std::string>& serialNumbers)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setDektecType(dektecType);
      setSerialNumbers(serialNumbers);
    }


    GetDektecSerialNumberAssignationResultPtr GetDektecSerialNumberAssignationResult::create(const std::string& dektecType, const std::vector<std::string>& serialNumbers)
    {
      return std::make_shared<GetDektecSerialNumberAssignationResult>(dektecType, serialNumbers);
    }

    GetDektecSerialNumberAssignationResultPtr GetDektecSerialNumberAssignationResult::create(CommandBasePtr relatedCommand, const std::string& dektecType, const std::vector<std::string>& serialNumbers)
    {
      return std::make_shared<GetDektecSerialNumberAssignationResult>(relatedCommand, dektecType, serialNumbers);
    }

    GetDektecSerialNumberAssignationResultPtr GetDektecSerialNumberAssignationResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetDektecSerialNumberAssignationResult>(ptr);
    }

    bool GetDektecSerialNumberAssignationResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["DektecType"])
          && parse_json<std::vector<std::string>>::is_valid(m_values["SerialNumbers"])
        ;

    }

    std::string GetDektecSerialNumberAssignationResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetDektecSerialNumberAssignationResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"DektecType", "SerialNumbers"}; 
      return names; 
    }


    std::string GetDektecSerialNumberAssignationResult::dektecType() const
    {
      return parse_json<std::string>::parse(m_values["DektecType"]);
    }

    void GetDektecSerialNumberAssignationResult::setDektecType(const std::string& dektecType)
    {
      setValue("DektecType", parse_json<std::string>::format(dektecType, m_values.GetAllocator()));
    }



    std::vector<std::string> GetDektecSerialNumberAssignationResult::serialNumbers() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["SerialNumbers"]);
    }

    void GetDektecSerialNumberAssignationResult::setSerialNumbers(const std::vector<std::string>& serialNumbers)
    {
      setValue("SerialNumbers", parse_json<std::vector<std::string>>::format(serialNumbers, m_values.GetAllocator()));
    }


  }
}
