#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <optional>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGalileoDataHealthForSV.
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             Satellite SV ID number 1..36.
    /// Component   string          Component is either "E5a", "E5b", or "E1B"
    /// Health      bool            False means Navigation data valid; True means Working without guarantee
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetGalileoDataHealthForSVResult;
    typedef std::shared_ptr<GetGalileoDataHealthForSVResult> GetGalileoDataHealthForSVResultPtr;
    
    
    class GetGalileoDataHealthForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetGalileoDataHealthForSVResult();

      GetGalileoDataHealthForSVResult(int svId, const std::string& component, bool health, const std::optional<std::string>& dataSetName = {});

      GetGalileoDataHealthForSVResult(CommandBasePtr relatedCommand, int svId, const std::string& component, bool health, const std::optional<std::string>& dataSetName = {});

      static GetGalileoDataHealthForSVResultPtr create(int svId, const std::string& component, bool health, const std::optional<std::string>& dataSetName = {});

      static GetGalileoDataHealthForSVResultPtr create(CommandBasePtr relatedCommand, int svId, const std::string& component, bool health, const std::optional<std::string>& dataSetName = {});
      static GetGalileoDataHealthForSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** component ****
      std::string component() const;
      void setComponent(const std::string& component);


      // **** health ****
      bool health() const;
      void setHealth(bool health);


      // **** dataSetName ****
      std::optional<std::string> dataSetName() const;
      void setDataSetName(const std::optional<std::string>& dataSetName);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetGalileoDataHealthForSVResult);
  }
}

