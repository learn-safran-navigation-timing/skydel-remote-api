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
    /// Set Galileo data health for I/NAV and F/NAV message
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             Satellite SV ID number 1..36.
    /// Component   string          Component is either "E5a", "E5b", or "E1B"
    /// Health      bool            False means Navigation data valid; True means Working without guarantee
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class SetGalileoDataHealthForSV;
    typedef std::shared_ptr<SetGalileoDataHealthForSV> SetGalileoDataHealthForSVPtr;
    
    
    class SetGalileoDataHealthForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetGalileoDataHealthForSV();

      SetGalileoDataHealthForSV(int svId, const std::string& component, bool health, const std::optional<std::string>& dataSetName = {});

      static SetGalileoDataHealthForSVPtr create(int svId, const std::string& component, bool health, const std::optional<std::string>& dataSetName = {});
      static SetGalileoDataHealthForSVPtr dynamicCast(CommandBasePtr ptr);
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


      // **** health ****
      bool health() const;
      void setHealth(bool health);


      // **** dataSetName ****
      std::optional<std::string> dataSetName() const;
      void setDataSetName(const std::optional<std::string>& dataSetName);
    };
    
  }
}

