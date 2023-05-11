#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"
#include "sdx_optional.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGpsDataHealthForSV.
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             Satellite's SV ID 1..32
    /// Health      int             Data health 0..7
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetGpsDataHealthForSVResult;
    typedef std::shared_ptr<GetGpsDataHealthForSVResult> GetGpsDataHealthForSVResultPtr;
    
    
    class GetGpsDataHealthForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsDataHealthForSVResult();

      GetGpsDataHealthForSVResult(int svId, int health, const Sdx::optional<std::string>& dataSetName = {});

      GetGpsDataHealthForSVResult(CommandBasePtr relatedCommand, int svId, int health, const Sdx::optional<std::string>& dataSetName = {});

      static GetGpsDataHealthForSVResultPtr create(int svId, int health, const Sdx::optional<std::string>& dataSetName = {});

      static GetGpsDataHealthForSVResultPtr create(CommandBasePtr relatedCommand, int svId, int health, const Sdx::optional<std::string>& dataSetName = {});
      static GetGpsDataHealthForSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** health ****
      int health() const;
      void setHealth(int health);


      // **** dataSetName ****
      Sdx::optional<std::string> dataSetName() const;
      void setDataSetName(const Sdx::optional<std::string>& dataSetName);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetGpsDataHealthForSVResult);
  }
}

