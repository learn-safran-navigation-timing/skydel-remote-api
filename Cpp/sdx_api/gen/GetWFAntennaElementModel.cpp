
#include "gen/GetWFAntennaElementModel.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetWFAntennaElementModel
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetWFAntennaElementModel::CmdName = "GetWFAntennaElementModel";
    const char* const GetWFAntennaElementModel::Documentation = "Get WF Antenna model for this element";

    REGISTER_COMMAND_FACTORY(GetWFAntennaElementModel);


    GetWFAntennaElementModel::GetWFAntennaElementModel()
      : CommandBase(CmdName)
    {}

    GetWFAntennaElementModel::GetWFAntennaElementModel(int element)
      : CommandBase(CmdName)
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
