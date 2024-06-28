
#include "GetWFAntennaElementModel.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetWFAntennaElementModel
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetWFAntennaElementModel::CmdName = "GetWFAntennaElementModel";
    const char* const GetWFAntennaElementModel::Documentation = "Please note the command GetWFAntennaElementModel is deprecated since 23.11. You may use GetWFElement.\n"
      "\n"
      "Get WF Antenna model for this element\n"
      "\n"
      "Name    Type Description\n"
      "------- ---- ---------------------------------------\n"
      "Element int  One-based index for element in antenna.";
    const char* const GetWFAntennaElementModel::TargetId = "";

    const char* const GetWFAntennaElementModel::Deprecated = "Please note the command GetWFAntennaElementModel is deprecated since 23.11. You may use GetWFElement.";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetWFAntennaElementModel);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetWFAntennaElementModel);


    GetWFAntennaElementModel::GetWFAntennaElementModel()
      : CommandBase(CmdName, TargetId)
    {}

    GetWFAntennaElementModel::GetWFAntennaElementModel(int element)
      : CommandBase(CmdName, TargetId)
    {

      setElement(element);
    }

    GetWFAntennaElementModelPtr GetWFAntennaElementModel::create(int element)
    {
      return std::make_shared<GetWFAntennaElementModel>(element);
    }

    GetWFAntennaElementModelPtr GetWFAntennaElementModel::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetWFAntennaElementModel>(ptr);
    }

    bool GetWFAntennaElementModel::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Element"])
        ;

    }

    std::string GetWFAntennaElementModel::documentation() const { return Documentation; }

    const std::vector<std::string>& GetWFAntennaElementModel::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Element"}; 
      return names; 
    }

    std::optional<std::string> GetWFAntennaElementModel::deprecated() const { return std::optional<std::string>{Deprecated}; }


    int GetWFAntennaElementModel::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetWFAntennaElementModel::element() const
    {
      return parse_json<int>::parse(m_values["Element"]);
    }

    void GetWFAntennaElementModel::setElement(int element)
    {
      m_values.AddMember("Element", parse_json<int>::format(element, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
