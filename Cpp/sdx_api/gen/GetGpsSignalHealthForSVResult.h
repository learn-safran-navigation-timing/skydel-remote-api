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
    /// Result of GetGpsSignalHealthForSV.
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             Satellite's SV ID 1..32
    /// Health      int             Signal health 0..31
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetGpsSignalHealthForSVResult;
    typedef std::shared_ptr<GetGpsSignalHealthForSVResult> GetGpsSignalHealthForSVResultPtr;
    
    
    class GetGpsSignalHealthForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsSignalHealthForSVResult();

      GetGpsSignalHealthForSVResult(int svId, int health, const Sdx::optional<std::string>& dataSetName = {});

      GetGpsSignalHealthForSVResult(CommandBasePtr relatedCommand, int svId, int health, const Sdx::optional<std::string>& dataSetName = {});

      static GetGpsSignalHealthForSVResultPtr create(int svId, int health, const Sdx::optional<std::string>& dataSetName = {});

      static GetGpsSignalHealthForSVResultPtr create(CommandBasePtr relatedCommand, int svId, int health, const Sdx::optional<std::string>& dataSetName = {});
      static GetGpsSignalHealthForSVResultPtr dynamicCast(CommandBasePtr ptr);
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
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetGpsSignalHealthForSVResult);
  }
}

