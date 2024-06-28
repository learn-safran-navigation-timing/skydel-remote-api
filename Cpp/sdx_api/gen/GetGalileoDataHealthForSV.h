#pragma once

#include <memory>
#include "command_base.h"

#include <optional>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get Galileo data health for I/NAV and F/NAV message
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             Satellite SV ID number 1..36.
    /// Component   string          Component is either "E5a", "E5b", or "E1B"
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetGalileoDataHealthForSV;
    typedef std::shared_ptr<GetGalileoDataHealthForSV> GetGalileoDataHealthForSVPtr;
    
    
    class GetGalileoDataHealthForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetGalileoDataHealthForSV();

      GetGalileoDataHealthForSV(int svId, const std::string& component, const std::optional<std::string>& dataSetName = {});

      static GetGalileoDataHealthForSVPtr create(int svId, const std::string& component, const std::optional<std::string>& dataSetName = {});
      static GetGalileoDataHealthForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** component ****
      std::string component() const;
      void setComponent(const std::string& component);


      // **** dataSetName ****
      std::optional<std::string> dataSetName() const;
      void setDataSetName(const std::optional<std::string>& dataSetName);
    };
    
  }
}

