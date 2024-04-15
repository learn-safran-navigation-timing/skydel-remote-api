#pragma once

#include <memory>
#include "command_base.h"

#include "sdx_optional.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get Galileo signal health for I/NAV and F/NAV message
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             The satellite's SV ID 1..36
    /// Component   string          Component is either "E5a", "E5b", or "E1B"
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetGalileoSignalHealthForSV;
    typedef std::shared_ptr<GetGalileoSignalHealthForSV> GetGalileoSignalHealthForSVPtr;
    
    
    class GetGalileoSignalHealthForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetGalileoSignalHealthForSV();

      GetGalileoSignalHealthForSV(int svId, const std::string& component, const Sdx::optional<std::string>& dataSetName = {});

      static GetGalileoSignalHealthForSVPtr create(int svId, const std::string& component, const Sdx::optional<std::string>& dataSetName = {});
      static GetGalileoSignalHealthForSVPtr dynamicCast(CommandBasePtr ptr);
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
      Sdx::optional<std::string> dataSetName() const;
      void setDataSetName(const Sdx::optional<std::string>& dataSetName);
    };
    
  }
}

