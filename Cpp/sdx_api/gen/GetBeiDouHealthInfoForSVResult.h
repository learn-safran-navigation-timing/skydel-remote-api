#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include "sdx_optional.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetBeiDouHealthInfoForSV.
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             Satellite SV ID 1..35, or use 0 to apply new value to all satellites.
    /// Health      int             Health Info, 9-bit integer : 0, 2, 64, 66, 128, 130, 192, 194, 256 or 511
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetBeiDouHealthInfoForSVResult;
    typedef std::shared_ptr<GetBeiDouHealthInfoForSVResult> GetBeiDouHealthInfoForSVResultPtr;
    
    
    class GetBeiDouHealthInfoForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetBeiDouHealthInfoForSVResult();

      GetBeiDouHealthInfoForSVResult(int svId, int health, const Sdx::optional<std::string>& dataSetName = {});

      GetBeiDouHealthInfoForSVResult(CommandBasePtr relatedCommand, int svId, int health, const Sdx::optional<std::string>& dataSetName = {});

      static GetBeiDouHealthInfoForSVResultPtr create(int svId, int health, const Sdx::optional<std::string>& dataSetName = {});

      static GetBeiDouHealthInfoForSVResultPtr create(CommandBasePtr relatedCommand, int svId, int health, const Sdx::optional<std::string>& dataSetName = {});
      static GetBeiDouHealthInfoForSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


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
    REGISTER_COMMAND_TO_FACTORY_DECL(GetBeiDouHealthInfoForSVResult);
  }
}

