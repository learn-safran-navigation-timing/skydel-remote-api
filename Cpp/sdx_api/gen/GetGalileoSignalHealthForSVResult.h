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
    /// Result of GetGalileoSignalHealthForSV.
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             The satellite's SV ID 1..36
    /// Component   string          Component is either "E5a", "E5b", or "E1B"
    /// Health      int             Signal health 0..3
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetGalileoSignalHealthForSVResult;
    typedef std::shared_ptr<GetGalileoSignalHealthForSVResult> GetGalileoSignalHealthForSVResultPtr;
    
    
    class GetGalileoSignalHealthForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGalileoSignalHealthForSVResult();

      GetGalileoSignalHealthForSVResult(int svId, const std::string& component, int health, const Sdx::optional<std::string>& dataSetName = {});

      GetGalileoSignalHealthForSVResult(CommandBasePtr relatedCommand, int svId, const std::string& component, int health, const Sdx::optional<std::string>& dataSetName = {});

      static GetGalileoSignalHealthForSVResultPtr create(int svId, const std::string& component, int health, const Sdx::optional<std::string>& dataSetName = {});

      static GetGalileoSignalHealthForSVResultPtr create(CommandBasePtr relatedCommand, int svId, const std::string& component, int health, const Sdx::optional<std::string>& dataSetName = {});
      static GetGalileoSignalHealthForSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** component ****
      std::string component() const;
      void setComponent(const std::string& component);


      // **** health ****
      int health() const;
      void setHealth(int health);


      // **** dataSetName ****
      Sdx::optional<std::string> dataSetName() const;
      void setDataSetName(const Sdx::optional<std::string>& dataSetName);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetGalileoSignalHealthForSVResult);
  }
}

